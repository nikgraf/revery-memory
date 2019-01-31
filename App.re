open Revery;
open Revery.Core;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let init = app => {
  let win = App.createWindow(app, "Memory");

  let render = () => <Game />;

  UI.start(win, render);
};

App.start(init);
