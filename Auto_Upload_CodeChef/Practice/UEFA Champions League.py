import sys
import math

def main(games):
    
    
    team_scores={}
    
    for e in games:
        
        team1,score1,x,score2,team2=e
        score1=int(score1)
        score2=int(score2)
        if team1 not in team_scores:
            
            team_scores[team1]=[0,0]
            
        if team2 not in team_scores:
            
            team_scores[team2]=[0,0]
        
        if score1>score2:
            team_scores[team1][0]+=3
        elif score2>score1:
            team_scores[team2][0]+=3
        else:
            team_scores[team1][0]+=1
            team_scores[team2][0]+=1
            
        team_scores[team1][1]+=score1-score2
        team_scores[team2][1]+=score2-score1
        
    res1,res2=[None,-float('inf'),-float('inf')],[None,-float('inf'),-float('inf')]
    
    s=sorted(team_scores.items(),key=lambda x:(x[1][0],x[1][1]),reverse=True)
    print(s[0][0],s[1][0])
    
    return
for _ in range(int(input())):
    games=[]
    for i in range(12):
        
        games.append(input().split())
    main(games)