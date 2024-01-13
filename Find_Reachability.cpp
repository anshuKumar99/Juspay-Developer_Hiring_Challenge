#include<bits/stdc++.h>
using namespace std;
vector<int>input[1000001];
void reachability(int A,int B,unordered_map<int,int>&mp){
	mp[A]=1;
	for(int i=0;i<input[A].size();i++){
		if(!mp[input[A][i]]){
			reachability(input[A][i],B,mp);
		}
	}
}

int main(){
	int n;
	cin>>n;
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){
		int id;
		cin>>id;
		mp[id]=0;
	}
	int edge;
	cin>>edge;

	for(int i=0;i<edge;i++){
		int follower,following;
		cin>>follower>>following;
		input[follower].push_back(following);
	}
	int A,B;
	cin>>A>>B;
	reachability(A,B,mp);
	cout<<mp[B]<<endl;
	return 0;	
}
