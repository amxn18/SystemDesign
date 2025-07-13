#include<bits/stdc++.h>
using namespace std;


// Abstract Base Class for Document Elements
class DocumentElements{
    public:
    virtual string render() = 0;
};

class TextElement : public DocumentElements {
    private:
    string text;
    public:
    TextElement(string text){
        this->text = text;
    }
    string render() override{
        return text + "\n";
    }
};

class ImageElement : public DocumentElements {
    private:
    string imagePath;
    public:
    ImageElement(string imagePath){
        this->imagePath = imagePath;
    }
    string render() override{
        return "Image: " + imagePath + "\n";
    }
};

// As the Above Classes Follow OCP, we can add more elements without changing the existing code.
class VideoElement : public DocumentElements {
    private:
    string videoPath;
    public:
    VideoElement(string videoPath){
        this->videoPath = videoPath;
    }
    string render() override{
        return "Video: " + videoPath + "\n";
    }
};

class TableElement : public DocumentElements {
    private:
    string tableData;
    public:
    TableElement(string tableData){
        this->tableData = tableData;
    }
    string render() override{
        return "Table: " + tableData + "\n";
    }
};


// Document Class For Holding Elements
class Document{
    vector<DocumentElements*> elements;   // Using vector of pointers to base class for polymorphism
    public:
    void addElement(DocumentElements* element) {
        elements.push_back(element);
    }
    string renderDocument() {
        string result;
        for (auto& element : elements) {
            result += element->render();
        }
        return result;
    }
    void removeElement(DocumentElements* element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }
};

// Abstract Class for Persistence
class Persistance{
    public:
    virtual void save(string data) = 0;
};

class SaveToLocalFileStorage : public Persistance {
    private:
    string filename;
    public:
    SaveToLocalFileStorage(string filename) {
        this->filename = filename;
    }
    void save(string data) override {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
};

class SaveToDB : public Persistance {
    void save(string data) override {
        cout << "Saving to database: " << data << endl;
    }
};

class SaveToCloud : public Persistance {
    void save(string data) override {
        cout << "Saving to cloud: " << data << endl;
    }
};

class DocumentEditor {
    private:
    Document* document;
    Persistance* storage;
    string renderedDocuments;
    public:
    DocumentEditor(Document* docs, Persistance* storage) {
        this->document = docs;
        this->storage = storage;
    }
    void addText(const string& text) {
        document->addElement(new TextElement(text));
    }
    void addImage(const string& imagePath) {
        document->addElement(new ImageElement(imagePath));
    }
    void addVideo(const string& videoPath) {
        document->addElement(new VideoElement(videoPath));
    }
    void addTable(const string& tableData) {
        document->addElement(new TableElement(tableData));
    }
    string renderDocument() {
        if(renderedDocuments.empty()) {
            renderedDocuments = document->renderDocument();
        }
        return renderedDocuments;
    }
    void saveDocument() {
        if (storage) {
            storage->save(renderDocument());
        } else {
            cerr << "No storage specified." << endl;
        }
    }
};

// Client Code
int main() {
    Document* doc = new Document();
    Persistance* storage = new SaveToLocalFileStorage("document.txt");
    DocumentEditor editor(doc, storage);

    editor.addText("Hello, World!");
    editor.addImage("image1.jpg");
    editor.addText("This is a test document.");
    editor.addVideo("video1.mp4");
    editor.addTable("Column1, Column2\nData1, Data2");

    cout << "Rendered Document:\n" << editor.renderDocument() << endl;

    editor.saveDocument();

    delete doc;
    delete storage;

    return 0;
}