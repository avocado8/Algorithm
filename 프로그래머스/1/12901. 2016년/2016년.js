
function solution(a, b) {
    const days = ['FRI','SAT','SUN','MON','TUE','WED','THU'];
    const month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let total = 0;
    for(let i=0;i<a-1;i++){
        total += month[i];
    }
    total += b-1;
    return days[total % 7];
}