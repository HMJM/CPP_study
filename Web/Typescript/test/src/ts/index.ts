interface Point {
  x: string,
  y: string,
}
type keys = keyof Point;
const a: keys = 'x';
console.log(a);
