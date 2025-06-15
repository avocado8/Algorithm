function solution(n, words) {
    // 바로 전 단어의 끝글자로 시작하지 않거나
    // 이전에 등장한 단어를 사용
    let arr = [];
    for(let i=0;i<words.length;i++){
        if(i===0) { //첫번째 단어 예외처리
            arr.push(words[i]);
            continue;
        }
        let prev = words[i-1];
        let cur = words[i];
        if(prev[prev.length-1]!==cur[0] || arr.find((w)=>w===cur)){
            return [(i % n) + 1, Math.floor(i / n)+1];
        } else arr.push(words[i]);
    }
    return [0,0];
}