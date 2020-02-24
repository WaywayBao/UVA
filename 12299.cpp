#include<iostream>		//uva 12299  RMQ with Shifts
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
int A[100010],min_value[300010],index,value,query_left,query_right;

void update(int node, int left, int right){
	if(left==right)	
		min_value[node]=value;		//leaf node
	else{
		int mid = (left+right)/2;
		if(index<=mid)			//find leaf node
			update(node*2,left,mid); 
		else		//find leaf node
			update(node*2+1,mid+1,right);
		min_value[node]=min(min_value[node*2],min_value[node*2+1]);		//decide which subtree has minimal value
	}
}

int query(int node, int left,int right){
	if(query_left<=left&&right<=query_right) 	//current subtree between the range
		return min_value[node];
	int mid= (left+right)/2, ans=0x3f3f3f3f;
	if(query_left<=mid) 		//search the minimal value in left subtree
		ans=min(ans,query(node*2,left,mid));
	if(mid<query_right)			//search the minimal value in right subtree
		ans=min(ans,query(node*2+1,mid+1,right));
	return ans;
}

int main(){
	int shift[15],n,q,temp;
	char operation[10],symbol;
	cin>>n>>q;
	for(int i=1;i<=n*3;++i) min_value[i]=0x3f3f3f3f;		//initial tree (all node) to infinitely large
	for(int i=1;i<=n;++i){
		cin>>A[i];
		index=i, value=A[i];
		update(1,1,n);
	}
	while(q--){
		getchar();		//read the buffer
		cin.getline(operation,10,'(');
		int s=0;
		do{
			cin>>shift[s++]>>symbol;
		}while(symbol==',');					
		if(operation[0]=='q'){		//query
			query_left=shift[0], query_right=shift[1];
			cout<<query(1,1,n)<<endl;
		}else{		//operation[0]=='s', shift		
			temp=A[shift[0]];
			for(int i=0;i<s-1;++i){
				index=shift[i], value=A[shift[i+1]];
				A[index]=value;
				update(1,1,n);
			}
			index=shift[s-1], value=temp;
			A[index]=value;			
			update(1,1,n);
		}
	}	
	return 0;
}



//---------Indentation
//#include<iostream>		//uva 12299  RMQ with Shifts
//#define min(a,b) (a)<(b)?(a):(b)
//using namespace std;
//int a[100010],min_value[270000],index,shift[15];
//int query(int node, int left,int right){
//	if(shift[0]<=left&&right<=shift[1]) return min_value[node];
//	int mid= (left+right)/2, ans=0x3f3f3f3f;
//	if(shift[0]<=mid) ans=min(ans,query(node*2,left,mid));
//	if(mid<shift[1]) ans=min(ans,query(node*2+1,mid+1,right));
//	return ans;
//}
//void update(int node, int left, int right){
//	if(left==right)	min_value[node]=a[index];		//leaf_node
//	else{
//		int mid = (left+right)/2;
//		if(index<=mid) update(node*2,left,mid); 
//		else update(node*2+1,mid+1,right);
//		min_value[node]=min(min_value[node*2],min_value[node*2+1]);
//	}
//}
//int main(){
//	int n,q,s,temp;
//	char operation[10],symbol;
//	cin>>n>>q;
//	for(int i=1;i<270000;++i) min_value[i]=0x3f3f3f3f;
//	for(index=1;index<=n;++index){
//		cin>>a[index];
//		update(1,1,n);
//	}
//	while(q--){
//		getchar();		//read the buffer
//		cin.getline(operation,10,'(');
//		s=0;
//		do{
//			cin>>shift[s++]>>symbol;
//		}while(symbol==',');
//		if(operation[0]=='q')
//			cout<<query(1,1,n)<<endl;
//		else{		//operation[0]=='s'
//			temp=a[shift[0]];
//			for(int i=0;i<s-1;++i){
//				index=shift[i], a[index]=a[shift[i+1]];
//				update(1,1,n);
//			}
//			index=shift[s-1],a[index]=temp;
//			update(1,1,n);
//		}
//	}	
//	return 0;
//}

