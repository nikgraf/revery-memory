open Revery;
open Revery.Core;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let noop = () => ();

let component = React.component(__MODULE__);

let make = (~color as c, ~visible, ~onClick, ()) =>
  component((_slots: React.Hooks.empty) => {
    let wrapperStyle =
      Style.[
        height(120),
        width(120),
        margin(30),
        boxShadow(
          ~yOffset=-9.,
          ~xOffset=-14.,
          ~blurRadius=14.,
          ~color=Colors.lightGrey,
          ~spreadRadius=14.,
        ),
        backgroundColor(visible ? c : Colors.white),
        /* to make colors appear in pastelle */
        opacity(0.8),
      ];

    let textHeaderStyle =
      Style.[
        color(Colors.white),
        fontFamily("canada1500-rg.ttf"),
        fontSize(20),
        margin(4),
      ];

    <Clickable onClick>
      <View style=wrapperStyle> <Text style=textHeaderStyle text="" /> </View>
    </Clickable>;
  });

let createElement = (~color as c, ~visible, ~onClick=noop, ~children as _, ()) =>
  React.element(make(~color=c, ~visible, ~onClick, ()));
