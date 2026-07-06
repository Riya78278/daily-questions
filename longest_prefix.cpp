//trie 
struct Node{
    Node *link[26]={nullptr};
    bool flag=false;

    bool containskey(char ch){
        return link[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node){
        link[ch-'a']=node;
    }

    Node* get(char ch){
        return link[ch-'a'];
    }

    void setflag(){
        flag=true;
    }

    bool isend(){
        return flag;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node* node=root;

        for(char ch:word){
            if(!node->containskey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }

        node->setflag();
    }

    bool searching(string word){
        Node* node=root;

        for(char ch:word){

            if(!node->containskey(ch)){
                return false;
            }

            node=node->get(ch);

            if(node->isend()==false){
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:

    string longestValidWord(vector<string>& words) {

        Trie trie;

        for(auto &it:words){
            trie.insert(it);
        }

        string longest="";

        for(auto &it:words){

            if(trie.searching(it)){

                if(it.size()>longest.size()){
                    longest=it;
                }
                else if(it.size()==longest.size() && it<longest){
                    longest=it;
                }
            }
        }

        return longest;
    }
};
