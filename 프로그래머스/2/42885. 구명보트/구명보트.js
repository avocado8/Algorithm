function solution(people, limit) {
    var answer = 0;
    people.sort((a,b)=>a-b);
    let left = 0; //젤가벼운애
    let right = people.length - 1; //젤무거운애
    while(left <= right){
        if(people[left]+people[right]<=limit){
            left++; //둘이 탈 수 있으면 가벼운애도 타기
        }
        right--; //무거운애는 어쨌든 타야됨
        answer++;
    }
    
    return answer;
}