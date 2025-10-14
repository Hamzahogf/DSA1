#include <iostream>

class FileSystem {
    private:
    struct Node
    {
        Node* child;
        Node* sibling;
        std::string name;
        int size;
        bool directory;
        int depth;
      Node(const std::string& dir = "", const std::string& str = "", int s = 0, int depth=0)
        : child(nullptr), sibling(nullptr), directory(!dir.empty()), name('/' + str), size(s), depth(0) {}
    };
    Node* head;
    bool isempty;
    int depthy;
    void deleteSubtree(Node* node) {
        if (!node) return;
        deleteSubtree(node->child);
        deleteSubtree(node->sibling);
        delete node;
    }
    int num_node(Node*& t){
        if(!t){return 0;} 
        else {return num_node(t->child)+num_node(t->sibling)+1;}
    }
    int num_leaf(Node*& t){
        if(!t){return 0;}
        else if(!t->child && !t->sibling){return 1;}
        else {return num_leaf(t->child)+num_leaf(t->sibling);}
    }
    int num_full_nodes(Node*& t){
        if(!t){return 0;}

        if(!t->child && t->sibling){return num_full_nodes(t->sibling);}
        else if(!t->sibling && t->child){return num_full_nodes(t->child);}
        else if(!t->child && !t->sibling){return 0;}
        else {return num_full_nodes(t->child)+num_full_nodes(t->sibling)+1;}
    }
    public:
    FileSystem(): head(nullptr) , isempty(true), depthy(0) {};
    ~FileSystem(){
        deleteSubtree(head);
    }
    Node* locateme(std::string path,int& depth){
        Node* current = head;
        std::string now;
        depth++;
        if(path.find_last_of('/')==0){ return current; }
        path=path.erase(0,1);
        path=path.erase(0, path.find('/'));
        path+='/';
        do
        {   depth++;
            if (path.find('/') == std::string::npos) //not exist
            {
                break;
            }
            path=path.erase(0,1);
            now= path.substr(0, path.find('/'));
            now = '/'+ now;
            if(current->child!=nullptr && current->child->name==now){
             current=current->child;
            } else if (current->sibling!=nullptr && current->sibling->name==now)
            {
             current=current->sibling;
            } else if(current->child!=nullptr && current->child->sibling!=nullptr){
            	current=current->child->sibling;
                while(current->name != now){ current=current->sibling ;}
            }
            path=path.erase(0, path.find('/'));
        } while (path.find_last_of('/')!=0 || path!="");
        return current;
    }
    void create(const std::string& path , const std::string& dir, const std::string& name, int s =0){ 
        Node* newnode= new Node(dir, name, s);
        if(isempty){
            head=newnode;
            isempty=false;
            std::cout << "Successfully added: " << newnode->name << std::endl;

            return;
        }
        int depth=0;
        Node* current = locateme(path,depth);
        depthy=(depth>=depthy)? depth:depthy; //update the depth of the tree
        newnode->depth=depth;
        if(current->child != nullptr && current->child->sibling==nullptr){
            current=current->child;
            current->sibling = newnode;
            std::cout << "Successfully added as sibling of " << path << std::endl;
        } else if(current->child != nullptr && current->child->sibling!=nullptr){
            current=current->child;
            while (current->sibling!=nullptr)
            {
                current=current->sibling;
            } 
            current->sibling=newnode;
            std::cout << "Successfully added as sibling of " << path << std::endl;
        } else {
            current->child=newnode;
            std::cout << "Successfully added as child of " << path << std::endl;
        }
    } 
    void print(int depth = 0, Node* now = nullptr) {
        if (!now) {
            now = head;
        }

        if (!now) return;

        for (int i = 0; i < depth; ++i) {
            std::cout << "  "; // Add indentation for visual hierarchy
        }

        std::cout << now->name << std::endl;

        if (now->directory && now->child) {
            print(depth + 1, now->child);
        }

        if (now->sibling) {
            print(depth, now->sibling); // Traverse siblings
        }
    }
    int num_node(){
        return num_node(head);
    }
    int num_leaf(){
        return num_leaf(head);
    }
    int depth(){
        return depthy;
    }
    int num_full_nodes(){
         return num_full_nodes(head);
    }
};



int main() {
    FileSystem fs; // Renamed object to `fs`

    std::string rootName = "root";
    int rootSize = 45;
    fs.create("", "directory", rootName, rootSize);
    std::cout<<" root "<<std::endl;

    std::string aName = "A";
    int aSize = 15;
    fs.create("/root", "directory", aName, aSize);
    std::cout<<" A "<<std::endl;

    std::string bName = "B";
    int bSize = 10;
    fs.create("/root", "directory", bName, bSize);
    std::cout<<" B "<<std::endl;
   
    std::string cName = "C";
    int cSize = 10;
    fs.create("/root", "directory", cName, cSize);
    std::cout<<" C "<<std::endl;
    
   
    std::string a1Name = "A1";
    int a1Size = 15;	
    fs.create("/root/A", "", a1Name, a1Size);
    std::cout<<" A1 "<<std::endl;    
    
    std::string b1Name = "B1";
    int b1Size = 10;
    fs.create("/root/B", "", b1Name, b1Size);
    std::cout<<" B1 "<<std::endl;

    
    std::string c1Name = "C1";
    int c1Size = 10;
    fs.create("/root/C", "", c1Name, c1Size);
    std::cout<<" C1 "<<std::endl;

    fs.print();

    std::cout<<"  num of node is : "<< fs.num_node() <<std::endl;
     std::cout<<"  num of leaf is : "<< fs.num_leaf() <<std::endl;
     std::cout<< " depth of tree :"<< fs.depth()<<std::endl;
     std::cout<<" num of full nodes : "<< fs.num_full_nodes() <<std::endl; 
    return 0;
}