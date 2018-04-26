module PairSet =
  Set.Make(
    {
      type t = (int, int);
      let compare = (a, b) => compare(a, b);
    }
  );