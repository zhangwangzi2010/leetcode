#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int>& nums);
void BubbleSort(vector<int>& items_array);
bool Verify(vector< vector<int> > total_array_list, vector<int>& items_array);
//static vector< vector<int> > select_list;

    vector< vector<int> > threeSum(vector<int>& nums) {
        //BubbleSort(nums);
        sort(nums.begin(), nums.end());

        int numbers_array = nums.size();
        vector< vector<int> > select_list;
        int prev_first_num = nums[0];
 
        for(int i = 0; i < numbers_array-2; i++) {
            if (i > 0) {
               if (nums[i] == prev_first_num) {
                  continue;
               } 
            }

            int target_2sum = 0 - nums[i];
            int head = i+1;
            int tail = numbers_array-1;
           
            while(head < tail) {
                int sum = nums[head] + nums[tail];
                //int prev_head_num = nums[head];
                //int prev_tail_num = nums[tail];

                if (sum == target_2sum) {
                    int items[3];
                    items[0] = nums[i];
                    items[1] = nums[head];
                    items[2] = nums[tail];
                    vector<int> items_array(items, items+3);
                    bool IsDupFlag = Verify(select_list, items_array);
                    if (IsDupFlag == false) {
                       select_list.push_back(items_array);
                    }
                  
                    head++;
                    tail--;
                    /*
                    while(nums[++head] == prev_head_num) {
                        prev_head_num = nums[head];
                    }    

                    while(nums[--tail] == prev_tail_num) {
                        prev_tail_num = nums[tail];                     
                    }
                    */
                }
                else if (sum < target_2sum) {
                    head++;
                    /*
                    while(nums[++head] == prev_head_num) {                         
                        prev_head_num = nums[head];
                    }
                    */
                }
                else {
                    tail--;
                    /*
                    while(nums[--tail] == prev_tail_num) {
                        prev_tail_num = nums[tail];
                    }
                    */
                }

            }

            prev_first_num = nums[i];
        }
       
        return select_list; 
    }
    
    void BubbleSort(vector<int>& items_array) {
        int array_size = items_array.size();
        for (int i = 0; i < array_size-1; i++) {
           for (int j = i; j < array_size; j++) {
              if (items_array[i] > items_array[j]) {
                 int temp = items_array[j];
                 items_array[j] = items_array[i];
                 items_array[i] = temp;
              }
           }
        }
    }

    bool Verify(vector< vector<int> > total_array_list, vector<int>& items_array) {
       for (int k = 0; k < total_array_list.size(); k++) {
          if (total_array_list[k][0] == items_array[0] &&
              total_array_list[k][1] == items_array[1] &&
              total_array_list[k][2] == items_array[2]) {
              return true;
          } 
       }
       return  false;
    }

int main(int argc, char* argv[])
{
    //int test_array[] = {-5,-9,0,4,-7,-5,7,-6,2,0,-6,4,1,-7,-5,-2,-8,8,-10};
    int test_array[] = {-1, 0, 1, 2, -1, -4};
    int array_size = sizeof(test_array)/sizeof(int);
    cout<<"input data size : "<<array_size<<endl;

    vector<int> input_data(test_array, test_array+array_size);
    vector< vector<int> > select_result_list = threeSum(input_data);
    cout<<select_result_list.size()<< "piece of 3items"<<endl;
    
    for (int k = 0; k < select_result_list.size(); k++) {
        cout<<k<<"th item list("<<select_result_list[k][0]<<", "<<select_result_list[k][1]<<", "<<select_result_list[k][2]<<")"<<endl;
    } 
   
    cout<<"Done...."<<endl;
    return 0;
}

