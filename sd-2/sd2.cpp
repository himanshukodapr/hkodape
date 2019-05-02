     

    #include <iostream>

    #include <cstdlib>

    #define MAX_VALUE 65536

    using namespace std;

     

  
     

    class Node

    {

    	public:

            int key;

            Node *left, *right;

            bool leftThread, rightThread; 

    };

     

    /* Class ThreadedBinarySearchTree */

     

    class ThreadedBinarySearchTree

    {

    	private:

            Node *root;

        public: 

            /* Constructor */

            ThreadedBinarySearchTree() 

            {

                root = new Node();

                root->right = root->left = root;

                root->leftThread = true;

                root->key = MAX_VALUE;

            }

     

            /* Function to clear tree */

            void makeEmpty()

            {

                root = new Node();

                root->right = root->left = root;

                root->leftThread = true;

                root->key = MAX_VALUE;

            }

     

           

            void insert(int key) 

            {

                Node *p = root;

                for (;;) 

                {

                    if (p->key < key) 

                    {

                        if (p->rightThread) 

                            break;

                        p = p->right;

                    } 

                    else if (p->key > key) 

                    {

                        if (p->leftThread) 

                            break;

                        p = p->left;

                    }

                    else 

                    {

                        /* redundant key */

                        return; 

                    }

                }

                Node *tmp = new Node();

                tmp->key = key;

                tmp->rightThread = tmp->leftThread = true;

                if (p->key < key) 

                { 

                    /* insert to right side */

                    tmp->right = p->right;

                    tmp->left = p;

                    p->right = tmp;

                    p->rightThread = false;

                }

                else

                {

                    tmp->right = p;

                    tmp->left = p->left;

                    p->left = tmp;

                    p->leftThread = false;

                }

            }

     

          

           

     

           
          
            void printTree() 

            {

                Node *tmp = root, *p;

                for (;;) 

                {

                    p = tmp;

                    tmp = tmp->right;

                    if (!p->rightThread) 

                    {

                        while (!tmp->leftThread) 

                        {

                            tmp = tmp->left;

                        }

                    }

                    if (tmp == root) 

                        break;

                    cout<<tmp->key<<"   ";

                }

                cout<<endl;

            }    

    };

     

    /* Main Contains Menu */

     

    int main()

    {            

        ThreadedBinarySearchTree tbst; 

        cout<<"ThreadedBinarySearchTree Test\n";          

        char ch;

        int choice, val;

        /*  Perform tree operations  */

        do    

        {

            cout<<"\nThreadedBinarySearchTree Operations\n";

            cout<<"1. Insert "<<endl;

            
            cout<<"Enter Your Choice: ";

            cin>>choice;

            switch (choice)

            {

            case 1 : 

                cout<<"Enter integer element to insert: ";

                cin>>val;

                tbst.insert(val);                     

                break;                          

            default : 

                cout<<"Wrong Entry \n ";

                break;   

            }

            /*  Display tree  */ 

            cout<<"\nTree = ";

            tbst.printTree();            

            cout<<"\nDo you want to continue (Type y or n): ";

            cin>>ch;                       

        } 

        while (ch == 'Y'|| ch == 'y');               

        return 0;

    }
