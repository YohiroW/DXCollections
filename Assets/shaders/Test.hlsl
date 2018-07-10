cbuffer ConstantBuffer : register( b0 )
{
	matrix M;
	matrix V;
	matrix P;
}

struct VS_INPUT
{
    float4 Pos : POSITION;
    float3 Norm : NORMAL;
};

struct PS_INPUT
{
    float4 Pos : SV_POSITION;
    float3 Norm : TEXCOORD0;
};


PS_INPUT VS( VS_INPUT input )
{
    PS_INPUT output = (PS_INPUT)0;
    output.Pos = mul( input.Pos, M );
    output.Pos = mul( output.Pos, V );
    output.Pos = mul( output.Pos, P );
    output.Norm = mul( input.Norm, M );
    
    return output;
}


float4 PS( PS_INPUT input) : SV_Target
{
	// use normal as color for now
    return input.Norm;
}

