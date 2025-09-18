model LinerForceWithTwoMass
  import Modelica.Units.SI;
  parameter SI.Mass m=1 "Mass of point masses";
  annotation(Diagram(coordinateSystem(extent={{-100,-100},{100,100}}, 
  grid={2,2})));
  inner Modelica.Mechanics.MultiBody.World world annotation (Placement(transformation(origin={-60,-45}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute1(phi(fixed=true), w(
        fixed=true)) annotation (Placement(transformation(origin={10,45}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.BodyBox bodyBox1(r={0.7,0,0}) 
    annotation (Placement(transformation(origin={50,45}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation rod1(
    r={0,-0.9,0}, 
    width=0.01, 
    animation=false) annotation (Placement(transformation(origin={-20,5}, 
extent={{-10,-10},{10,10}}, 
rotation=270)),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Joints.Assemblies.JointUPS jointUPS(nAxis_ia={0.7,1.2,0}, animation= 
       true) annotation (Placement(transformation(origin={20,-5}, 
extent={{-12,12},{12,-12}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.Body body1(
    r_CM=0.2*jointUPS.eAxis_ia, 
    cylinderDiameter=0.05, 
    animation=true, 
    m=m, 
    I_11=0, 
    I_22=0, 
    I_33=0) annotation (Placement(transformation(origin={-10,-17}, 
extent={{10,-10},{-10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.Body body2(
    r_CM=-0.2*jointUPS.eAxis_ia, 
    cylinderDiameter=0.05, 
    animation=true, 
    m=m, 
    I_11=0, 
    I_22=0, 
    I_33=0) annotation (Placement(transformation(origin={50,-17}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation rod2(
    r={0,0.3,0}, 
    width=0.01, 
    animation=false) annotation (Placement(transformation(origin={-20,35}, 
extent={{10,-10},{-10,10}}, 
rotation=270)),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.Translational.Components.Damper damper1(
                                                  d=3) 
    annotation (Placement(transformation(origin={20,-35}, 
extent={{-10,10},{10,-10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Joints.Revolute revolute2(phi(fixed=true), w(
        fixed=true)) annotation (Placement(transformation(origin={10,-65}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.BodyBox bodyBox2(r={0.7,0,0}) 
    annotation (Placement(transformation(origin={50,-65}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation rod3(
    width=0.01, 
    r={0,-0.9,0.3}, 
    animation=false) annotation (Placement(transformation(origin={-20,-115}, 
extent={{-10,-10},{10,10}}, 
rotation=270)),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Parts.FixedTranslation rod4(
    width=0.01, 
    r={0,0.3,0.3}, 
    animation=false) annotation (Placement(transformation(origin={-20,-75}, 
extent={{10,-10},{-10,10}}, 
rotation=270)),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.Translational.Components.Damper damper2(
                                                  d=3) 
    annotation (Placement(transformation(origin={20,-99}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
  Modelica.Mechanics.MultiBody.Forces.LineForceWithTwoMasses 
    lineForceWithTwoMasses(
    L_a=0.2, 
    L_b=0.2, 
    cylinderLength_a=0.2, 
    cylinderLength_b=1.2, 
    massDiameterFaction=2.2, 
    m_a=m, 
    m_b=m) annotation (Placement(transformation(origin={20,-125}, 
extent={{-10,-10},{10,10}})),__MWORKS(BlockSystem(StateMachine)));
equation
  connect(jointUPS.bearing, damper1.flange_a) 
  annotation(Line(origin={12.6,-26}, 
  points={{2.6000000000000005,9},{2.6000000000000005,1},{-2.5999999999999996,1},{-2.5999999999999996,-9}}, 
  color={0,127,0}));
  connect(jointUPS.axis, damper1.flange_b) 
  annotation(Line(origin={27.4,-26}, 
  points={{-2.6000000000000005,9},{-2.6000000000000005,1},{2.5999999999999996,1},{2.5999999999999996,-9}}, 
  color={0,127,0}));
  connect(jointUPS.frame_ib, body2.frame_a) 
  annotation(Line(origin={34.8,-17}, 
  points={{-5.200000000000001,0},{5.199999999999999,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(world.frame_b, rod2.frame_a) 
  annotation(Line(origin={-35,-10}, 
  points={{-15,-35},{-5,-35},{-5,29},{15,29},{15,35}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(world.frame_b, rod1.frame_a) 
  annotation(Line(origin={-35,-13}, 
  points={{-15,-32},{-5,-32},{-5,32},{15,32},{15,28}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(rod2.frame_b, revolute1.frame_a) 
  annotation(Line(origin={-10,45}, 
  points={{-10,0},{10,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(revolute1.frame_b, bodyBox1.frame_a) 
  annotation(Line(origin={30,45}, 
  points={{-10,0},{10,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(bodyBox1.frame_b, jointUPS.frame_b) 
  annotation(Line(origin={51,20}, 
  points={{9,25},{19,25},{19,-25},{-19,-25}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(body1.frame_a, jointUPS.frame_ia) 
  annotation(Line(origin={5.199999999999999,-17}, 
  points={{-5.199999999999999,0},{5.200000000000001,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(rod1.frame_b, jointUPS.frame_a) 
  annotation(Line(origin={-6,-5}, 
  points={{-14,0},{14,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(rod4.frame_b, revolute2.frame_a) 
  annotation(Line(origin={-10,-65}, 
  points={{-10,0},{10,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(revolute2.frame_b, bodyBox2.frame_a) 
  annotation(Line(origin={30,-65}, 
  points={{-10,0},{10,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(world.frame_b, rod4.frame_a) 
  annotation(Line(origin={-35,-70}, 
  points={{-15,25},{-5,25},{-5,-25},{15,-25},{15,-15}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(rod3.frame_a, rod4.frame_a) 
  annotation(Line(origin={-20,-95}, 
  points={{0,-10},{0,10}}, 
  thickness=0.5));
  connect(lineForceWithTwoMasses.frame_a, rod3.frame_b) 
  annotation(Line(origin={-5,-125}, 
  points={{15,0},{-15,0}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(lineForceWithTwoMasses.frame_b, bodyBox2.frame_b) 
  annotation(Line(origin={50,-95}, 
  points={{-20,-30},{20,-30},{20,30},{10,30}}, 
  color={95,95,95}, 
  thickness=0.5));
  connect(lineForceWithTwoMasses.flange_b, damper2.flange_b) 
  annotation(Line(origin={28,-106.5}, 
  points={{-2,-7.5},{2,-7.5},{2,7.5}}, 
  color={0,127,0}));
  connect(lineForceWithTwoMasses.flange_a, damper2.flange_a) 
  annotation(Line(origin={12,-106.5}, 
  points={{2,-7.5},{-2,-7.5},{-2,7.5}}, 
  color={0,127,0}));

end LinerForceWithTwoMass;