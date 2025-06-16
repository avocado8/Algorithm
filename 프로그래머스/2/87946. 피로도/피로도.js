function getPermutation(arr, num){
    if(num===1){ // 1개 남으면 그냥 그거 리턴ㄱ (재귀종료)
        return arr.map((el)=>[el]);
    }
    const result = [];
    arr.forEach((el, originalIdx, array) => {
        const fix = el; //첫 원소 고정
        const rest = array.filter((_, restIdx) => restIdx !== originalIdx); // 고정한 원소 제외하고 나머지 원소들
        const permOfRest = getPermutation(rest, num-1); //rest에 대해 재귀호출, rest 원소들 가지고 순열구하기
        permOfRest.forEach((e) => {
            result.push([fix, ...e]);
        })
    })
    return result;
}

function solution(k, dungeons) {
    let result = [];
    const perms = getPermutation(dungeons, dungeons.length)
    for(let cand of perms){
        let cur_score = k; //피로도
        let count = 0; //탐색 던전 수
        //[[80,20],[50,40],[30,10]]
        for(let dungeon of cand){
            let least_score = dungeon[0]; //최소필요피로도
            let paid_score = dungeon[1]; //소모필요도
            if(least_score <= cur_score){ //탐색 가능하면
                count++; //탐색
                cur_score -= paid_score; //피로도 차감
            }
        }
        result.push(count);
    }
    return Math.max(...result);
}