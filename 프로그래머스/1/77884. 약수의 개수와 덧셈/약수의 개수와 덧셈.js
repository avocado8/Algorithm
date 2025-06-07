function getSubs(num){
    let cnt = 0;
    for(let i=0;i*i<=num;i++){
        if(num % i === 0) {
            cnt++;
            if(i !== (num / i)) cnt++;
        }
        
    }
    return cnt;
}

function solution(left, right) {
    var answer = 0;
    for(let i = left;i<=right;i++){
        let cnt = getSubs(i);
        // console.log(cnt);
        cnt%2==0 ? answer+=i : answer-=i;
    }
    return answer;
}