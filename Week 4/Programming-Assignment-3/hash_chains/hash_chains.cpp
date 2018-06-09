#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    size_t bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector<vector<string>> arr_hash;
    
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count1){
		bucket_count = bucket_count1;
		//arr_hash.resize(1000000000);
	} 

    Query readQuery() const {
        
        Query query;
         
        cin >> query.type;
        // cout<<"done "<<query.type <<"\n";
        if (query.type != "check")
        { 
            cin >> query.s;
        
        }
        else{
     //      string a;
       //     cin>>a;
            cin>>query.ind;
         //    cout<<"here "<<a<<"\n";
        }
        //cout<<"done \n";
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        
		
		if(query.type=="add"){
			size_t int_hash = hash_func(query.s);
            vector<string> temp = arr_hash[int_hash];
			if(temp.empty()){
				//vector<string> temp;
          //      cout<<"New "<<int_hash<<" " <<query.s<<'\n';
				temp.push_back(query.s);
				arr_hash[int_hash] = temp;
			}
			else{
				//vector<string> temp = arr_hash[int_hash];
				vector<string>::iterator it = std::find(temp.begin(), temp.end(), query.s);
                //cout<<"Old "<<int_hash<<" " <<query.s<<'\n';
				if (it == temp.end()){
                    
					arr_hash[int_hash].push_back(query.s);
					//arr_hash[int_hash] = temp;
                    //cout<<"Old "<<int_hash<<" " <<query.s<<" " <<arr_hash[int_hash].size()<<'\n';
				}
			}
		}
		else if(query.type=="find"){
            //cout<<"find \n";
			size_t int_hash = hash_func(query.s);
			vector<string> temp = arr_hash[int_hash];
			vector<string>::iterator it = std::find(temp.begin(), temp.end(), query.s);
			writeSearchResult(it != temp.end());
		}
		else if(query.type=="del"){
            //cout<<"del \n";
			size_t int_hash = hash_func(query.s);
			vector<string> temp = arr_hash[int_hash];
			vector<string>::iterator it = std::find(temp.begin(), temp.end(), query.s);
			if (it != temp.end()){
				temp.erase(it);
				arr_hash[int_hash] = temp;
			}
		}
		else if(query.type=="check"){
            //cout<<"check "<<query.ind <<"\n";
			vector<string> temp = arr_hash[query.ind];
			if(!temp.empty()){
                //cout<<"hello \n";
				for(int i= temp.size()-1;i>=0;i--)
					cout<<temp[i]<<" ";

			}
			cout<<'\n';
		}
		
    }

    void processQueries() {
        arr_hash.resize(bucket_count,vector<string>());
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i){
        //    cout<<i<<" ";
            processQuery(readQuery());
            
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    //cout<<"here";
    QueryProcessor proc(bucket_count);
    
    proc.processQueries();
    return 0;
}
