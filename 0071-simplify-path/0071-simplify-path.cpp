class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        //wnated to extract dir names form path, i.e strings b/w / & /
        string s = "";
        for(int i=0;i<path.size();i++){
            if(path[i] != '/'){
                s = s + path[i];
            }
            else{
                if(s.size() == 0);
                else if(s == ".");
                else if(s == ".."){
                    if(!dir.empty()) dir.pop();
                }
                else dir.push(s);
                cout<<s<<endl;
                s = "";
            }
        }
        cout<<s<<endl;

        if(s.length() == 0);
        else if(s == ".") ;
        else if(s == ".."){
            if(!dir.empty()) dir.pop();
        }
        else dir.push(s);
        
        string res = "";
        while(!dir.empty()){
            res =  "/" + dir.top() + res;
            dir.pop();
        }
        if(res == "") res = "/";
        return res;
    }
};