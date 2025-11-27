#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    //시전시간, 초당회복량, 추가회복량
    //몇초에, 몇을 때린다.
    
    int lastattacktime = 0;
    
    int use_time = bandage[0];
    int heal_persecond = bandage[1];
    int plus_heal = bandage[2];
    int current_hp = health;
    
    
    for(vector<int> v : attacks)
    {
        current_hp += (v[0]-lastattacktime-1)*heal_persecond;

        if(v[0]-lastattacktime > use_time)
        {
         current_hp += ((v[0]-lastattacktime-1)/use_time)*plus_heal;
        }
        
        if(current_hp > health) current_hp = health;

        current_hp-=v[1];
        if(current_hp <= 0) return -1;
        
        lastattacktime = v[0];
    }
    
    
    return current_hp;
}