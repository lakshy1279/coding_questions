
//in this we swap the two node in the sorted array 
// prev node should be always less than the currentnode if not then this is the faulty node.
//Recursive solution
private:
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(first==NULL&&(prev==NULL||prev->val>=root->val))
            first=prev;
        if(first!=NULL&&prev->val>=root->val)
            second=root;
        prev=root;
        inorder(root->right);
    }
public:
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }

// Morris inorder trvaersal solution
public void recoverTree(TreeNode root) {
        TreeNode pre = null;
        TreeNode first = null, second = null;
        // Morris Traversal
        TreeNode temp = null;
		while(root!=null){
			if(root.left!=null){
				// connect threading for root
				temp = root.left;
				while(temp.right!=null && temp.right != root)
					temp = temp.right;
				// the threading already exists
				if(temp.right!=null){
				    if(pre!=null && pre.val > root.val){
				        if(first==null){first = pre;second = root;}
				        else{second = root;}
				    }
				    pre = root;
				    
					temp.right = null;
					root = root.right;
				}else{
					// construct the threading
					temp.right = root;
					root = root.left;
				}
			}else{
				if(pre!=null && pre.val > root.val){
				    if(first==null){first = pre;second = root;}
				    else{second = root;}
				}
				pre = root;
				root = root.right;
			}
		}
		// swap two node values;
		if(first!= null && second != null){
		    int t = first.val;
		    first.val = second.val;
		    second.val = t;
		}
    }
