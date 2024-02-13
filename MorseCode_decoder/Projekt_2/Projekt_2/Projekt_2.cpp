#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class MorseTree {
public:
    MorseTree() {
        // Populate the tree with Morse code mappings
        // Each node in the tree has a mapping to its left and right children
        root = new Node();
        insert(root, 'E', ".", "-");
        insert(root, 'T', "-", ".");
        insert(root, 'A', ".-", NULL);
        insert(root, 'N', "-.", NULL);
        insert(root, 'M', "--", NULL);
        insert(root, 'I', "..", NULL);
        insert(root, 'O', "---", NULL);
        insert(root, 'G', "--.", NULL);
        insert(root, 'K', "-.-", NULL);
        insert(root, 'D', "-..", NULL);
        insert(root, 'W', ".--", NULL);
        insert(root, 'R', ".-.", NULL);
        insert(root, 'U', "..-", NULL);
        insert(root, 'S', "...", NULL);
        insert(root, 'Q', "--.-", NULL);
        insert(root, 'Y', "-.--", NULL);
        insert(root, 'C', "-.-.", NULL);
        insert(root, 'F', "..-.", NULL);
        insert(root, 'V', "...-", NULL);
        insert(root, 'J', ".---", NULL);
        insert(root, 'Z', "--..", NULL);
        insert(root, 'X', "-..-", NULL);
        insert(root, 'B', "-...", NULL);
        insert(root, 'P', ".--.", NULL);
        insert(root, 'H', "....", NULL);
        insert(root, 'L', ".-..", NULL);
        insert(root, ' ', "/", "//");
    }

    string decode(string morse) {
        string message = "";
        Node* current = root;
        for (char c : morse) {
            if (c == '/') {
                if (current == root) {
                    message += " ";
                }
                else if (current->left == NULL && current->right == NULL) {
                    message += current->value;
                    current = root;
                }
                else {
                    message += current->value;
                    current = root;
                }
            }
            else if (c == '.') {
                current = current->left;
            }
            else if (c == '-') {
                current = current->right;
            }
        }
        if (current != root) {
            message += current->value;
        }
        return message;
    }

private:
    struct Node {
        char value;
        Node* left;
        Node* right;
        Node() {
            value = '\0';
            left = NULL;
            right = NULL;
        }
        Node(char v) {
            value = v;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    void insert(Node* current, char value, const char* left_morse, const char* right_morse) {
        if (*left_morse != '\0') {
            if (current->left == NULL) {
                current->left = new Node();
            }
            insert(current->left, value, left_morse + 1, right_morse);
        }
        if (*right_morse != '\0') {
            if (current->right == NULL) {
                current->right = new Node();
            }
            insert(current->right, value, left_morse, right_morse + 1);
        }
        if (*left_morse == '\0' && *right_morse == '\0')
        {
            cout << endl;
        }
    }
}
int main() 
{
        // Open the input and output files
        ifstream input_file("input.txt");
        ofstream output_file("output.txt");

        // Read the Morse code message from the input file
        string morse;
        getline(input_file, morse);

        // Create a MorseTree object and decode the message
        MorseTree tree;
        string message = tree.decode(morse);

        // Write the decoded message to the output file
        output_file << message << endl;

        // Close the input and output files
        input_file.close();
        output_file.close();

    return 0;
}
