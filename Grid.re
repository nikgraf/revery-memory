open Revery;
open Revery.Core;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let split = (list, n) => {
  let rec aux = (index, acc) =>
    fun
    | [] => (List.rev(acc), [])
    | [head, ...rest] as l =>
      if (index == 0) {
        (List.rev(acc), l);
      } else {
        aux(index - 1, [head, ...acc], rest);
      };
  aux(n, [], list);
};

let component = React.component(__MODULE__);

let rowStyle =
  Style.[
    flexDirection(`Row),
    alignItems(`Center),
    justifyContent(`Center),
  ];

let make = children => {
  let (firstRow, secondRow) = split(children, 4);

  component((_slots: React.Hooks.empty) =>
    <View>
      <View style=rowStyle> ...firstRow </View>
      <View style=rowStyle> ...secondRow </View>
    </View>
  );
};

let createElement = (~children, ()) => React.element(make(children));
