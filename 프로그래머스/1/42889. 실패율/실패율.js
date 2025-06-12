function solution(N, stages) {
    var attend = Array(N).fill(0); //도전
    var fail = Array(N).fill(0); //도달못함
    for(let i=0;i<stages.length;i++){
        let tmp = stages[i];
        if(tmp <= N) {
            fail[tmp-1]++;
        } else tmp = N;
        for(let j=tmp;j>0;j--){
            // 2면 1,2  4면 1,2,3,4...
            attend[j-1]++;
        }
    }
    console.log(attend)
    console.log(fail)
    
    let failRate = [];
    for(let i=0;i<attend.length;i++){
        failRate.push(fail[i] / attend[i]);
    }
    const withIndex = failRate.map((value, idx) => ({value, idx}));
    withIndex.sort((a,b)=>b.value-a.value);
    console.log(withIndex)
    const failRateIndex = withIndex.map(el => el.idx + 1);
    console.log(failRateIndex)
    
    return failRateIndex;
    
}