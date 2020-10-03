vector<string> Solution::restoreIpAddresses(string ip) {
    
    // https://www.interviewbit.com/problems/valid-ip-addresses/
    
    vector<string> ans;
    
    int n = ip.size();
    if(n<4 || n>12) return ans;
    
    string a,b,c,d;
    a = b = c = d = "";
    
    for(int i=1; i<=3; i++)
    {
        if(!(n-i >= 3 && n-i<=9)) continue;
        if(i>1 && ip[0] == '0') break;
        
        a = ip.substr(0,i);
        if(stoi(a) > 255) continue;
        
        //cout << a << endl;
        
        for(int j=1;j<=3; j++)
        {
            if(!(n-(i+j) >= 2 && n-(i+j)<=6)) continue;
            if(j>1 && ip[i] == '0') break;
            
            b = ip.substr(i, j);
            if(stoi(b) > 255) continue;
            
            //cout << a << "." << b << endl;
            
            for(int k=1; k<=3; k++)
            {
                if(!(n-(i+j+k) >= 1 && n-(i+j+k)<=3)) continue;
                if(k>1 && ip[i+j] == '0') break;
                
                c = ip.substr(i+j, k);
                if(stoi(c) > 255) continue;
                
                //cout << a << "." << b << "." << c << endl;
                
                int l = n-(i+j+k);
                if(l>1 && ip[i+j+k] == '0') continue;
                
                d = ip.substr(i+j+k, l);
                if(stoi(d) > 255) continue;
                
                d = a + '.' + b + '.' + c + '.' + d;
                //cout << d << endl;
                
                ans.push_back(d);
            }
        }
    }
    
    return ans;
}
