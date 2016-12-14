import XMonad

main :: IO ()
main = xmonad def {
  manageHook = className =? "dependent-window-move" --> doFloat
}
