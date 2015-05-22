
#ifndef WAVETEST_H
#define WAVETEST_H
class WaveTest : public Test
{
    public:
    int scale = 30;
    public:
        WaveTest()
        {
            b2BodyDef myBodyDef;
            myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
            myBodyDef.position.Set(0, 20); //set the starting position
            myBodyDef.angle = 0; //set the starting angle
            b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);

            b2PolygonShape boxShape;
            boxShape.SetAsBox(1,1);

            b2FixtureDef boxFixtureDef;
            boxFixtureDef.shape = &boxShape;
            boxFixtureDef.density = 1;
            dynamicBody->CreateFixture(&boxFixtureDef);

            CreateWalls();

        } //do nothing, no scene yet

        void CreateWalls()
        {
            int w = 720;
            int h = 480;
        }

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings);

            //show some text in the main screen
            m_debugDraw.DrawString(5, m_textLine, "Wave test");
            m_textLine += 15;
         }

         static Test* Create()
         {
            return new WaveTest;
         }
};

class Wave
{
public:

};
#endif
