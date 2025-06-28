function strToTime(time){
    return Number(time.substr(0,2))*60 + Number(time.substr(3,2));
}

function solution(book_time) {
    var answer = 1;

    book_time.sort((a,b)=>strToTime(a[0]) - strToTime(b[0]));
    let heap = [];
    for(let [start, end] of book_time){
        let start_time = strToTime(start);
        let end_time = strToTime(end) + 10;
        
        // heap에는 종료 시각을 저장
        // 종료 시각이 빠른 것부터 정렬
        heap.sort((a,b) => a-b);
        if(heap.length && heap[0] <= start_time){
            // 현재 가장 빠른 종료시각보다 이번손님의 시작시각이 늦으면 해당객실 사용가능
            // 다 사용한 손님 나가기
            heap.shift();
        }
        heap.push(end_time);
    }
    
    
    return heap.length;
}