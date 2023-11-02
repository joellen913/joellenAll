{-Joellen Allah-Mensah
10/10/2023 
CSC4510 - Prog Lang Design/Translation
File location: /home/students/jallah/csc4510/assignment5/functional/diffhask.hs
About: 
This Haskell program is a user-friendly geometry calculator, offering
options for rectangle and triangle area and perimeter, as well as
circle circumference calculations. Users input values, and the program
computes and displays results. It also handles invalid choices
and allows for multiple calculations in a single session.

We compile this file with the command:
ghc -o diffhask diffhask.hs

We create an executable file called multiply, which can then be executed by typing:
./diffhask.hs (or ./a.out)
-}
 
 -- imports the text.printf library to use "printf" for working with the floating-point numbers
import Text.Printf

-- function to take in three doubles and calculate the area of a rectangle while also naming the double variables
rectangleArea :: Double -> Double -> Double
rectangleArea length width = length * width

-- function to take in three doubles and calculate the perimeter of a rectangle while also naming the double variables 
rectanglePerimeter :: Double -> Double -> Double
rectanglePerimeter length width = 2 * (length + width)

-- function to take in three doubles and calculate the area of a triangle while also naming the variables
triangleArea :: Double -> Double -> Double
triangleArea base height = 0.5 * base * height

-- function to take in three doubles and calculate the perimeter of a triangle while also naming the variables
trianglePerimeter :: Double -> Double -> Double -> Double
trianglePerimeter side1 side2 side3 = side1 + side2 + side3

-- function to take in three doubles and calculate the circumference of a circle while also naming the variables
circleCircumference :: Double -> Double
circleCircumference radius = 2 * pi * radius

-- main function: prints out options for geometry calculator 
main :: IO ()
main = do
    putStrLn "Geometry Calculator"
    putStrLn "1. Calculate the area of a rectangle"
    putStrLn "2. Calculate the perimeter of a rectangle"
    putStrLn "3. Calculate the area of a triangle"
    putStrLn "4. Calculate the circumference of a circle"
    putStrLn "5. Quit"
    putStr "Please select an option: "

    -- read the user's choice as a string and converts it to an integer
    choice <- getLine
    let option = read choice :: Int -- uses "let" to create option vriable and assign it to choice user makes 

    -- uses additional "case-do" feature to cycle through user options 
    case option of
        1 -> do -- does first option
            putStrLn "Enter the length of the rectangle:"
            lengthStr <- getLine -- gets length of the rectangle 
            let length = read lengthStr :: Double -- reads in string length, assigns it to length variable

            putStrLn "Enter the width of the rectangle:"
            widthStr <- getLine -- gets the width of the rectangle
            let width = read widthStr :: Double -- reads in rectangle width, assigns it to width variable

            let area = rectangleArea length width 
            printf "The area of the rectangle is: %.2f\n" area

        2 -> do -- does second option 
            putStrLn "Enter the length of the rectangle:"
            lengthStr <- getLine -- gets the length of the rectangle
            let length = read lengthStr :: Double -- reads in string length, assigns it to length variable 

            putStrLn "Enter the width of the rectangle:"
            widthStr <- getLine -- gets the width of the rectangle 
            let width = read widthStr :: Double -- reads in string width, assigns it to width variable 

            let perimeter = rectanglePerimeter length width -- assigns perimeter variable to rectanglePerimiter function from above, taking in length and width values 
            printf "The perimeter of the rectangle is: %.2f\n" perimeter -- prints perimeter 

        3 -> do -- does third option 
            putStrLn "Enter the base of the triangle:"
            baseStr <- getLine -- gets the base of the triangle
            let base = read baseStr :: Double -- reads in string base, assigns it to base variable 

            putStrLn "Enter the height of the triangle:"
            heightStr <- getLine -- gets the height of the triangle 
            let height = read heightStr :: Double -- reads in triangle height, assigns it to height variable 

            let area = triangleArea base height -- assigns area variable to triangleArea function, using previous inputs of base and height 
            printf "The area of the triangle is: %.2f\n" area -- prints result 

        4 -> do -- does fifth option 
            putStrLn "Enter the radius of the circle:"
            radiusStr <- getLine -- gets circles radius 
            let radius = read radiusStr :: Double -- reads in the string radius, assign it to variable radius thats a double 

            let circumference = circleCircumference radius -- assigns circumference variable to the circleCircumference function, taking in radius input 
            printf "The circumference of the circle is: %.2f\n" circumference -- prints out circumference


        5 -> putStrLn "Done." -- states that you chose to quit case-do switch

        --  input invalidation
        _ -> putStrLn "Invalid option, please choose a vald option."

    -- out of loop, uses recursive call to the main function for multiple calculations once done
    main -- found recursive call information for haskell here: https://stackoverflow.com/questions/57979596/haskell-ok-to-recursively-call-main

