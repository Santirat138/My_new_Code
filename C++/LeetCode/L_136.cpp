#include<iostream>
#include<vector>
using namespace std;
//--------------------------- class toolsBox
class toolsBox{
	public:
		vector<int> mainArray;
		vector<int> skipArray;
		toolsBox(){
			vector<int> tempArray={5, 7, 1, 9, 7, 3, 7, 5, 5};
			mainArray=tempArray;
		}
		bool isInArray(vector<int> arrayIn, int numIn);
		void selectSkipIdx();
        void onlyNotSkipIdx();
};
bool toolsBox::isInArray(vector<int> arrayIn, int numIn){
	for(int i=0;i<arrayIn.size();i++){
		if(numIn==arrayIn.at(i)){
			return true;
		}
	}
	return false;
}
void toolsBox::selectSkipIdx(){
	int currNum;
	for(int curr=0;curr<mainArray.size();curr++){
		currNum=mainArray.at(curr);
		for(int check=0;check<mainArray.size();check++){
			if(mainArray.at(check)==mainArray.at(curr)){
				if(check==curr){
					continue;
				}
				if(!isInArray(skipArray, check)){
					skipArray.push_back(check);
				}
			}
		}
	}
}
void toolsBox::onlyNotSkipIdx(){
    for(int i=0;i<mainArray.size();i++){
        if(isInArray(skipArray, i)){
            continue;
        }
        else{
            cout<<mainArray.at(i)<<" ";
        }
    }
}
//--------------------------- main
int main(){
	toolsBox tool;
	tool.selectSkipIdx();
    tool.onlyNotSkipIdx();
}