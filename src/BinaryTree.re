type state = {
  visited: array(int),
  edges: Generator.PairSet.t,
  frontier: list((int, int)),
  next: list((int, int)),
  step: int
};

let size = 5;

let init = () => {
  let start = Random.int(size);
  {
    visited: Array.make(size, 0),
    edges: Generator.PairSet.empty,
    frontier: [(start, start)],
    next: [],
    step: 0
  }
};

let edges = (state) => state.edges;

let visited = (state) => state.visited;

let max_age = (state) => state.step;

let sortpair = (a, b) => a > b ? (b, a) : (a, b);

let add_edges = (adjacents, state, (pre, src)) => {
  state.visited[src] = state.step + 1;
  let next =
    List.fold_left(
      (next, dest) =>
        if (state.visited[dest] > 0) {
          next
        } else {
          state.visited[dest] = state.step + 1;
          [(src, dest), ...next]
        },
      state.next,
      adjacents
    );
  (next, Generator.PairSet.add(sortpair(pre, src), state.edges), state.step + 1)
};

let step = (get_adjacent, state) => {
    switch state.frontier {
        | [] => state,
        | [(pre, src)] =>
            let (frontier, edges, step) = add_edges(get_adjacent(src), state, (pre, src));
            (...state, frontier)
    };
}