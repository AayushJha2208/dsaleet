class Solution {
public:
    string convert(string s, int numRows) {
        if (size(s)==1 || numRows==1) return s;
        string p="";
        int j=0;
        int k;
        for(int i=0;i<numRows;i++){
            k=j;
            if(i==0 || i==numRows-1){
                while(j<size(s)){
                    p.push_back(s[j]);
                    j+=(2*numRows)-2;    
                }
            }
            else{
                while(j<size(s)){
                    p.push_back(s[j]);
                    j+=2*(numRows-i-1);
                    if(j>=size(s)) break;
                    p.push_back(s[j]);
                    j+=2*(i-1) +2;
                }
            }
            j=k+1;
        }
        return p;
    }
};;