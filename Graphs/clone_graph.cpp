/*
    using DFS
*/
void dfs(Node* node, Node* copy, vector<Node*> &vis)
{
    // record in vis array
    vis[copy->val] = copy;
    for(auto curr : node->neighbors)
    {
        // if not visited
        if(vis[curr->val] == null)
        {
            // make new node
            Node* newNode = new Node(curr->val);
            // save in neighbour of prev
            (copy->neighbors).push_back(newNode);
            //do dfs in both
            dfs(curr,newNode,vis);
        }
        else
        {
            // visited then push the address of visited in copy's neighbors
            (copy->neighbors).push_back(vis[curr->val]);
        }
    }
}

Node* cloneGraph(Node* node)
{
    if(!node)
    {
        return NULL;
    }
    vector<Node*> vis(1000,NULL);
    Node* newNode = new Node(node->val);
    dfs(node,newNode,vis);
    return newNode;
}