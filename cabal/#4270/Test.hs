module Test where

import Foo

import Distribution.TestSuite

tests :: IO [Test]
tests = return [Test bar]
  where
    bar = TestInstance
        { run = return $ Finished run
        , name = "test"
        , tags = []
        , options = []
        , setOption = \_ _ -> Right bar
        }
    run = if foo == 42 then Pass else Fail "should be equal"
