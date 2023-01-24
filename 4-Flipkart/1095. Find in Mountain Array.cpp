/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr,int s,int e,int n){
        int mid = (s+e)/2;
        while(s<=e){
            mid = (s+e)/2;
            int mVal = mountainArr.get(mid);
            int l = mVal , r = mVal;
            if(mid-1>=0)l = mountainArr.get(mid-1);
            if(mid+1<n)r = mountainArr.get(mid+1);
            if(l<mVal&&r<mVal)break;
            if(l>mVal){
                e = mid-1;
            }else s = mid+1;
        }
        return mid;
    }
    int findElement(MountainArray &mountainArr, int s, int e,int target,bool asc){
        int mid = (s+e)/2;
        bool found = false;
        while(s<=e){
            mid = (s+e)/2;
            int mVal = mountainArr.get(mid);
            if(mVal==target){
                found = true;
                break;
            }
            if(asc){
                if(mVal<target){
                    s= mid+1;
                }else if(mVal>target) e = mid-1;
            }else{
                if(mVal>target)s = mid+1;
                else if(mVal<target) e = mid-1;
            }
        }
        return found?mid:-1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, 0, n-1,n);
        int left = findElement(mountainArr,0,peak-1,target,true);
        int right = findElement(mountainArr,peak,n-1,target,false);
        cout<<peak<<" "<<left<<" "<<right<<endl;
        if(left==-1&&right ==-1)return -1;
        return min((left!=-1?left:n),(right!=-1?right:n));
    }
};