class Solution {
public:// pep explanation 
    
    bool check(int i, int j, int n){
        if(i>=0 && i<n && j>=0 && j<n) return true;
        
        return false;
    }
    
    double knightProbability(int n, int k, int r, int c) {
        
           double **curr = new double*[n];
        for(int i=0; i<n; i++){
            curr[i]=new double[n];
        }
    
        
       double **next = new double*[n];
        for(int i=0; i<n; i++){
            next[i]=new double[n];
        }  
        
        
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    curr[i][j]=0;
                    next[i][j]=0;
                }
            }
        // memset(curr, 0, sizeof(curr));
        
        
        curr[r][c]=1;  // k=0
        
        for(int count=1; count<=k; count++)
        {
            // memset(next, 0, sizeof(next));
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                if(curr[i][j]!=0){
                        
                    int ni, nj; // new i, new j
                        
                    nj = j+1;
                    ni = i-2;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    
                    nj = j+2;
                    ni = i-1;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    nj = j+2;
                    ni = i+1;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    
                    nj = j+1;
                    ni = i+2;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    
                    nj = j-1;
                    ni = i+2;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    nj = j-2;
                    ni = i+1;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    nj = j-2;
                    ni = i-1;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    nj = j-1;
                    ni = i-2;
                    if(check(ni,nj,n))
                        next[ni][nj] += curr[i][j]/8.0; 
                    
                    }
                }
            }
            
            curr=next;
            next = new double*[n];
            for(int i=0; i<n; i++)
            {
                next[i]=new double[n];
            }  
             
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    
                    next[i][j]=0;
                }
            }
            
        }
        
    double ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans+=curr[i][j];
        }
    }
    return ans;
    }

};