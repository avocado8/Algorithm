function solution(n) {
    let result = 0;
    let prev1 = 0, prev2=1;
    for(let i=2;i<=n;i++){
        result = (prev1 + prev2)%1234567;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}