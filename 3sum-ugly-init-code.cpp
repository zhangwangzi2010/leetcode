#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > threeSum(vector<int>& nums);
void SortThreeDigits(vector<int>& items_array);
bool Verify(vector< vector<int> > total_array_list, vector<int>& items_array);
//static vector< vector<int> > select_list;

    vector< vector<int> > threeSum(vector<int>& nums) {
        int numbers_array = nums.size();
        vector< vector<int> > select_list;
        int index = -1;
 
        for(int i = 0; i < numbers_array-2; i++) {
            for (int j = i+1; j < numbers_array-1; j++) {
                for (int k = j+1; k < numbers_array-1; k++) {
                    index++;
                    int items[3];
                    items[0] = nums[i];
                    items[1] = nums[j];
                    items[2] = nums[k];
                    cout<<index<<" : "<<items[0]<<", "<<items[1]<<", "<<items[2]<<endl;

                    if ((items[0]+items[1]+items[2]) == 0) {
                        vector<int> threedigits(items, items+3);
                        SortThreeDigits(threedigits);
                        bool IsDupFlag = Verify(select_list, threedigits);
                        if (IsDupFlag == false) {
                           select_list.push_back(threedigits);
                        }
                    }
                }
            }
        }
       
        return select_list; 
        
    }
    
    void SortThreeDigits(vector<int>& items_array) {
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
    int test_array[] = {-5,-9,0,4,-7,-5,7,-6,2,0,-6,4,1,-7,-5,-2,-8,8,-10};
    int array_size = sizeof(test_array)/sizeof(int);

    vector<int> input_data(test_array, test_array+array_size);
    vector< vector<int> > select_result_list = threeSum(input_data);
    cout<<select_result_list.size()<< "piece of 3items"<<endl;
    
    for (int k = 0; k < select_result_list.size(); k++) {
        cout<<k<<"th item list("<<select_result_list[k][0]<<", "<<select_result_list[k][1]<<", "<<select_result_list[k][2]<<")"<<endl;
    } 
   
    cout<<"Done...."<<endl;
    return 0;
}

