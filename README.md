# Final Project CS120

For my final project I created a platforming game. I was inspired as a combo of geometry dash and give up.

## Running my game

Copy the repo and have the required matterial for running glut and gl.
I have run this program on mac however it should also work on windows if you have the set up done properly.
When running this game please ensure that the resolution of the screen you are using is over a 1000 in both directions as my game is designed for this resolution only.

## Summary

Through creating this game I have learned a lot of things about game development. I have implemented a rudimentary gravity system that I would work to improve upon in a future project.
One of the biggest problems I ran into was a limitation of glut. Simply glut when using key boards does not pass the state of the key into the function for keyboard.
This simple detail that was present in the mouse pressed function but not the keyboard for some reason leads to very inconsistent movement when playing. Due to this I had to make a few development decisions to ensure the game was playable at all.
I made is so that any contact at all with the platform would put you on top of it. This is not something I had wished to do but the game would be simply unplayable and terrible if not for this. 
I was unable to find a suitable fix for this problem on the internet that I could get to work sadly. I also included the ability to jump consecutively, the inconsistent side to side movement leads to very imprecise jumps. If you would like a real challenge do not jump unless you are on the ground.

Other then that there are three levels of a very simple platforming game I created. you can move using either the arrow keys or wasd. You complete a level by getting to the dark blue square. Good luck have fun. Thank you for a great class I hope you have a great day.