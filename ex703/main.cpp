#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Comparator{
    public:
        bool operator()(int a,int b)
        {
            if(a<b)
                return true;
            return false;
        }
};

class KthLargest {
    
public:
    int k;
    vector<int> v;

    //priority_queue<Nod*,vector<Nod*>,Comparator> c;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        v.push_back(val);
        priority_queue<int,vector<int>,Comparator> c;
        int i, nr;

        for(i=0;i<v.size();i++)
            c.push(v[i]);
        for(i=0;i<k;i++)
        {
            nr=c.top();
            c.pop();
        }
        return nr;
    }
};


int main()
{
    // vector <int> v={4,5,8,2};
    // KthLargest *obj = new KthLargest(3,v);
    // cout << obj->add(3)<<endl; //4
    // cout << obj->add(5)<<endl; // return 5
    // cout << obj->add(10)<<endl; // return 5
    // cout << obj->add(9)<<endl; // return 8
    // cout << obj->add(4)<<endl; //8

    vector <int> v={7,7,7,7,8,3};
    KthLargest *obj = new KthLargest(4,v);
    cout << obj->add(2)<<endl; //7
    cout << obj->add(10)<<endl; // return 7
    cout << obj->add(9)<<endl; // return 7
    cout << obj->add(9)<<endl; // return 8
    return 0;
}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */