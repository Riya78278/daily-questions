// using trie

struct Node{
    Node *link[26]={nullptr};
    bool flag=false;
    
    //coontainkey
    bool containkey(char ch){
        return link[ch-'a']!=nullptr;
    }
    //put
    void put(char ch,Node * node){
        link[ch-'a']=node;
    }
    
    //get
    Node* get(char ch){
        return link[ch-'a'];
    }
    
    //setend
    void setend(){
        flag=true;
    }
    
    bool isend(){
        return flag;
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int count=0;
        Node*root=new Node();
        for(int i=0;i<s.size();i++){
            Node*node=root;
            for(int j=i;j<s.size();j++){
                if(!node->containkey(s[j])){
                    count++;
                    node->put(s[j],new Node());
                    
                }
                node=node->get(s[j]);
            }
            node->setend();
            
        }
        return count;
        
    }
};
