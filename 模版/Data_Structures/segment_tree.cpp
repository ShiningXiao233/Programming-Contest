
#include <algorithm>
using namespace std;

/**
 * 动态开点线段树
 */
template<typename POSTYPE = int, typename ANSTYPE = int>
class dynamic_seg_tree
{
    dynamic_seg_tree* lson;
    dynamic_seg_tree* rson;
    POSTYPE l, r;
    POSTYPE len;
    /*... 其他辅助参数*/

public:
    /**
     * 构造函数，构造时使用包含的范围
     * _l 左端点
     * _r 右端点
     */
    dynamic_seg_tree(POSTYPE _l, POSTYPE _r) : l(_l), r(_r), len(_r - _l + 1), 
    lson(nullptr), rson(nullptr) {}

    void init(POSTYPE _l, POSTYPE _r) {
        l = _l;
        r = _r;
        len = r - l + 1;
        lson = rson = nullptr;
    }

    /**
     * 析构函数，一下删除以当前点为根的子树
     * 目前是内存申请版本，可以尝试使用内存池技术
     */
    ~dynamic_seg_tree() {
        if (lson != nullptr) delete lson;
        if (rson != nullptr) delete rson;
    }

    /**
     * 合并子节点信息，作用为普通版本的push_up
     */
    void merge_son() {
        
    }

    void push_down() {

    }

    /** 
     * 更新区间/节点信息
     */
    void update() {

        if (/* 满足区间要求*/) {

            return;
        }

        int mid = (l + r) >> 1;
        if (lson == nullptr) {
            lson = new dynamic_seg_tree(l, mid);
            rson = new dynamic_seg_tree(mid + 1, r);
        }

        push_down();

        if (/* 满足左端点 */) lson->update(/* 参数 */);
        else if (/* 满足右端点 */) rson->update(/* 参数 */);
        
        merge_son();
    }
    /**
     * 查询
     */
    ANSTYPE query(/* 参数 */) {
        if (/* */) {
            return ANSTYPE();
        }
        push_down();

        if (/* 满足左端点 */) {
            return lson->query(/* 参数 */);
        }
        else if (/* 满足右端点 */) {
            return rson->query(/* 参数 */);
        }

    }
};