function solution(n,a,b)
{
    let answer = 0;
    while(1){
        if(Math.ceil(a/2) != Math.ceil(b/2)){
            a = Math.ceil(a/2);
            b = Math.ceil(b/2);
            answer++;
        } else break;
    }
    return ++answer;
}
// 7 : (7)vs8 - 3vs(4) - 1vs(2)
