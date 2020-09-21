struct Tr {
    int siz, v, prio, lch, rch;
};
Tr tr[400005];
int S, root;
void maintain(int x){
    // 更新 x 的子树大小
    tr[x].siz = 1 + tr[tr[x].lch].siz + tr[tr[x].rch].siz;
}
void init_env(){
    // 初始化相关变量
    S = 0; root = 0; tr[0].siz = 0;
    srand(time(NULL));
}
int tree_new(int k){
    // 分配一个新节点
    ++S;
    tr[S].siz = 1, tr[S].v = k, 
    tr[S].prio = rand(), 
    tr[S].lch = tr[S].rch = 0;
    return S;
}
void Split(int now, int k, int &x, int &y){
    if (!now) x = y = 0;
    else {
        if (tr[now].v <= k){
            x = now, Split(tr[now].rch, k, tr[now].rch, y);
        }else {
            y = now, Split(tr[now].lch, k, x, tr[now].lch);
        }
        maintain(now);
    }
}
void Split_K(int now, int k, int &x, int &y){
    if (!now) x = y = 0;
    else {
        if (k > tr[tr[now].lch].siz){
            x = now, Split_K(tr[now].rch, k - tr[tr[now].lch].siz - 1, tr[now].rch, y);
        }else {
            y = now, Split_K(tr[now].lch, k, x, tr[now].lch);
        }
        maintain(now);
    }
}
int Merge(int x, int y){
    if (!x || !y) return x + y;
    if (tr[x].prio < tr[y].prio){
        // y 所有节点的值 > x，故接到 x 的右子树上
        tr[x].rch = Merge(tr[x].rch, y);
        maintain(x);
        return x;
    }else{
        // x 所有节点的值 < y，故接到 y 的左子树上
        tr[y].lch = Merge(x, tr[y].lch);
        maintain(y);
        return y;
    }
}