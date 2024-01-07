string encode(string src)
{     
  //Your code here 
    string ans = "";
    int n = src.size();
    char curr = src[0];
    int count = 1;
    for(int i = 1; i < n; i++){
        if(src[i] == curr) count ++;
      
        else{
            ans += curr;
            ans += to_string(count);
            count = 1;
            curr = src[i];
        }
    }
    ans += curr;
    ans += to_string(count);
    return ans;
  
}  