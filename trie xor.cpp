struct Node {
    // Array to hold links to child nodes (0 and 1)
    Node *links[2];

    // Function to check if a child node exists for a given bit
    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }

    // Function to get the child node for a given bit
    Node* get(int ind) {
        return links[ind];
    }

    // Function to create a link to a child node for a given bit
    void put(int ind, Node* node) {
        links[ind] = node;
    }
};

// Class for Trie operations
class Trie {
private:
    // Pointer to the root node
    Node* root;

public:
    // Constructor to initialize the trie
    Trie() {
        root = new Node();
    }

    // Function to insert a number into the trie
    void insert(int num) {
        // Start from root
        Node* node = root;

        // Traverse bits from MSB (31) to LSB (0)
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // If path for this bit doesn't exist, create it
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            // Move to the next node
            node = node->get(bit);
        }
    }

    // Function to find maximum XOR for a given number
    int findMax(int num) {
        // Start from root
        Node* node = root;

        // Variable to store maximum XOR result
        int maxNum = 0;

        // Traverse bits from MSB to LSB
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // Try to take the opposite bit for maximizing XOR
            if (node->containsKey(!bit)) {
                // Set this bit in the result
                maxNum = maxNum | (1 << i);

                // Move to the opposite branch
                node = node->get(!bit);
            } 
            // If opposite bit doesn't exist, move to same bit branch
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),0);
        vector<pair<int,pair<int,int>>>oq;
        sort(nums.begin(),nums.end());
        int index=0;
        for(auto &it:queries){
            oq.push_back({it[1],{it[0],index++}});
        }
        sort(oq.begin(),oq.end());
        int i=0;
        int n=nums.size();

        Trie trie;
        for(auto &it:oq){
            while(i <n && nums[i]<=it.first){
                trie.insert(nums[i]);
                i++;

            }
            if(i!=0){
                ans[it.second.second]=trie.findMax(it.second.first);
            }
            else{
                ans[it.second.second]=-1;
            }
        }
        return ans;
    }
};
