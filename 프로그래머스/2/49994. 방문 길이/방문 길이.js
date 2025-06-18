function move(x, y, dir){
    //(x,y)에서 dir방향으로 이동
    if(dir==="U" && y+1<=5) return [x, y+1];
    else if(dir==="D" && y-1>=-5) return [x, y-1];
    else if(dir==="R" && x+1 <=5) return [x+1, y];
    else if(dir==="L" && x-1>=-5) return [x-1, y];
    return [x,y];
}

function solution(dirs) {
    var answer = 0;
    // 길 경로 저장: 시작점과 끝점?
    const ways = new Set();
    let cur = [0,0];
    
    for(let i=0;i<dirs.length;i++){
        let next = move(cur[0], cur[1], dirs[i]);
        if(cur[0]!==next[0] || cur[1]!==next[1]){
            const path = [cur, next]
            .sort(([x1,y1],[x2,y2])=>{ //좌표 작은것부터 정렬
                if(x1===x2) return y1-y2;
                return x1-x2;
            }).map(([x, y])=>`${x},${y}`)
            .join('/');
            ways.add(path);
        }
        cur = next;
        // console.log(ways)
    }
    return ways.size;
}