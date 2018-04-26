type direction =
  | Up
  | Down
  | Right
  | Left;

let adjacent = [Up, Down, Right, Left];

let adjacent_coord = (direction) =>
  switch direction {
  | Up => (0, (-1))
  | Down => (0, 1)
  | Right => (1, 0)
  | Left => ((-1), 0)
  };