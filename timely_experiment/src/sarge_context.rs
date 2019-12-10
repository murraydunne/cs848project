
use timely::Data;
use std::clone::Clone;
use timely::ExchangeData;
use abomonation::Abomonation;

#[derive(Copy, Clone)]
pub struct SargeContext {
    pub dest_replica: u64,
    pub source_replica: u64,
    pub pipe_stage: u64,
    pub num_rtcs: u64,
    pub num_replicas: u64,
    pub is_rtc: bool,
}

unsafe_abomonate!(SargeContext : node, stage);
