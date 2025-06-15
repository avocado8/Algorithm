function solution(n) {
    let result = 0;
    let tmp1 = 1, tmp2 = 1;
    if(n===1) return 1;
    for(let i=1;i<n;i++){
        result = (tmp1 + tmp2) % 1234567;
        tmp1 = tmp2;
        tmp2 = result;
    }
    
    return result;
}
//F: 0 1 1 2 3 5....
//한번에 1 or 2
// n = (n-2) + (n-1)
// 1칸 -> 1가지 (F(2))
// 2칸 -> (1,1) (2) 2가지 (F(3))
// 3칸 -> (1,1,1) (1,2) (2,1) 3가지
// 4칸 -> (1,1,1,1) (1,2,1)(1,1,2) (2,1,1) (2,2) 5가지 
