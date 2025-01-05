// Сейчас я попробую показать две резализации дерева отрезков, которые я считаю достойными внмания
// Задачей будет обновление на отрезке и сумма на отрезке
#include <iostream>
#include <vector>
#include <array>
// Дерево отрезков в быстром и приятном виде
#ifdef tulizh // иногда хочется для дебага, локально создавать маленькую дошку, а в систему уже большую
const int N = 1 << 7; // наименьшая покрывающая степень двойки
#else
const int N = 1 << 16;
#endif
// int t[2 * N]; 
// так писать не надо потому что это вообщем-то наследие из С, 
//у такого массива нет встроенных проверок на выход за границы, поэтому дебажить это больно

std::array<int, 2 * N> t; // а вот такой массив мне уже нравится

void set_val(int i, int x) {
    i += N;
    t[i] = x;
    i /= 2;
    while (i) {
        t[i] = t[i * 2] + t[i * 2 + 1];
        i /= 2;
    } 
    // любители нечитаемого кода могу сократить это до
    // for (t[i += N] = x, i /= 2; ; i /= 2) t[i] = t[i * 2] + t[i * 2 + 1];
}
int get(int ql, int qr, int l, int r, int v) { // [ql; qr), [l; r)
    if (ql >= r || l >= qr) {
        return 0;
    }
    if (ql <= l && r <+ qr) {
        return t[v];
    }
    return get(ql, qr, l, (l + r) / 2, v * 2) + get(ql, qr, (l + r) / 2, r, v * 2 + 1);
}

struct seg_tree {
    struct node {
        int val = 0, l, r;
        // node *lnode, *rnode; // может появиться желание писать эту дошку на указателях
        node() = default;
        node(int i) : l(i), r(i + 1) {
        }
        node(int i, int x) : node(i) {
            val = x;
        }
        static node merge(node l, node r) {
            node ans;
            ans.l = l.l;
            ans.r = r.r;
            ans.val = l.val + r.val;
            return ans;
        }
    };
    std::vector<node> t;
    int N;
    seg_tree(int n) {
        N = 1;
        while (N < n) {
            N *= 2;
        }
        t.resize(N * 2);
    }
    void set_val(int i, int x, int l, int r, int v) {
        if (t[v].r - t[v].l == 1) {
            t[i] = node(x);
            return;
        }
    }
    node get_val(int ql, int qr, int l, int r, int v) { // здесь возвращать ноду вовсе не обязательно но иногда хочется
        if (t[v].l > qr || l > t[v].r) {
            return 0;
        }
        if (ql <= t[v].l && t[v].r <= qr) {
            return t[v];
        }
        return node::merge(get_val(ql, qr, l, (l + r) / 2, v * 2), get_val(ql, qr, (l + r) / 2, r, v * 2 + 1));
    }
};