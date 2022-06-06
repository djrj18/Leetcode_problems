class TextEditor {
public:
    string Before,After;
    TextEditor() {
        Before = "";
        After = "";
    }
    
    void addText(string text) {
        Before.insert(Before.length(),text);        
    }
    
    int deleteText(int k) {
        k = min(k,(int)Before.length());
        Before.resize(Before.length()-k);
        return k;
    }
    
    string cursorLeft(int k) {
        
        int l = Before.length();
        for(int i = 0 ; i < min(k,l) ; i++){
            After.push_back(Before.back());
            Before.pop_back();
        }
       
        return Before.length() <= 10 ? Before : Before.substr((int)Before.length() - 10,10);
    }
    
    string cursorRight(int k) {
        int l = After.length();
        for(int i = 0 ; i < min(k,l) ;i++){
            Before.push_back(After.back());
            After.pop_back();
        }
        return Before.length() <= 10 ? Before : Before.substr((int)Before.length() - 10,10);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */