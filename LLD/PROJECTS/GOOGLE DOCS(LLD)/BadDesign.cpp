#include<bits/stdc++.h>
using namespace std;

class DocumentEditor {
    private:
    vector<string> elements;
    string renderedDocuments;
    public:
    void addText(const string& text) {
        elements.push_back(text);
    }
    void addImage(const string& imagePath) {
        elements.push_back("<img src='" + imagePath + "'/>");
    }

    // Bussiness Logic 
    string renderDocument() {
        if(renderedDocuments.empty()) {
            string result;
            for (const auto& element : elements) {
                if(element.size() > 4 && (element.substr(element.size()-4) == ".jpg" || element.substr(element.size()-4) == ".png")) {
                    result += "Image: " + element + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocuments = result;
        }
        return renderedDocuments;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << renderDocument();
            file.close();
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
};
// Client Code
int main(){
    DocumentEditor editor;
    editor.addText("Hello, World!");
    editor.addImage("image1.jpg");
    editor.addText("This is a test document.");
    editor.addImage("image2.png");

    cout << "Rendered Document:\n" << editor.renderDocument() << endl;

    editor.saveToFile("document.txt");

    return 0;
}