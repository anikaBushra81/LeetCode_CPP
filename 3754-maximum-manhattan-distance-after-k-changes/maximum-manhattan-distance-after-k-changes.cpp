// class Solution {
// public:
//     int maxDistance(string s, int k) {
//         int n=s.size();

//         vector<pair<int,int>>path(n+1);

//         int x=0,y=0;
//         path[0]={0,0};

//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='N')
//             {
//                 y++;
//             }
//             else if(s[i]=='S'){
//                 y--;
//             }
//             else if(s[i]=='E'){
//                 x++;
//             }
//             else if(s[i]=='W'){
//                 x--;
//             }

//             path[i+1]={x,y};
//         }

//         // int baseDist=abs(x)+abs(y);
//         int baseDist = 0;
//         for (int i = 1; i <= n; i++) {
//             baseDist = max(baseDist, abs(path[i].first) + abs(path[i].second));
//             }


//         vector<int>improvements;

//         for(int i=0;i<n;i++)
//         {
//             int dx=0,dy=0;

//             if(s[i]=='N')
//             {
//                 dy=1;
//             }
//             else if(s[i]=='S')
//             {
//                 dy=-1;
//             }
//             else if(s[i]=='E')
//             {
//                 dx=1;
//             }
//             else  if(s[i]=='W')
//             {
//                 dx=-1;
//             }
//             int prevX=path[i].first;
//             int prevY=path[i].second;

//             int oldX=prevX+dx;
//             int oldY=prevY+dy;
//             int oldDist=abs(oldX)+abs(oldY);

//             for(char dir:{'N','S','E','W'}){
//                 if(s[i]==dir){
//                     continue;
//                     }

//                 int ndx=0,ndy=0;

//                 if(dir=='N')
//                 {
//                     ndy=1;
//                 }
//                 else if(dir=='S')
//                 {
//                     ndy=-1;
//                 }
//                 else if(dir=='E')
//                 {
//                     ndx=1;
//                 }
//                 else if(dir=='W')
//                 {
//                     ndx=-1;
//                 }

//                 int newX=prevX+ndx;
//                 int newY=prevY+ndy;

//                 int newDist=abs(newX)+abs(newY);

//                 int diff=newDist-oldDist;
//                 improvements.push_back(diff);



//         }

//     }

//     sort(improvements.rbegin(),improvements.rend());

//     for(int i=0;i<k&&i<improvements.size();i++)
//     {
//         if(improvements[i]>0){
//             baseDist+=improvements[i];
//         }
//     }
        
//         return baseDist;
        
//     }
// };


// 



class Solution{
public:
    int maxDistance(string s, int k){
        int latiTude=0,longiTude=0,maxDist=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            switch(s[i])
            {
                case 'N':
                    latiTude++;
                    break;

                case 'S':
                    latiTude--;
                    break;

                case 'E':
                    longiTude++;
                    break;

                case 'W':
                    longiTude--;
                    break;
            }

            maxDist=max(maxDist,min(abs(latiTude) + abs(longiTude)+2*k,i+1));
        }
        return maxDist;
    }
};